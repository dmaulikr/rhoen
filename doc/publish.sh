#!/bin/sh

# The following environment variables must be set:
# - GH_REPO_NAME        : The name of the repository.
# - GH_REPO_REF         : The GitHub reference to the repository.
# - GH_REPO_TOKEN       : Secure token to the github repository.
# - TRAVIS_COMMIT       : Will be automatically set by Travis CI.

set -e
cd `dirname $0`

# Abort if required environment variables are not set
if [ -z ${GH_REPO_NAME} ] || [ -z ${GH_REPO_REF} ] ||
   [ -z ${GH_REPO_TOKEN} ] || [ -z ${TRAVIS_COMMIT} ]; then
	echo "" >&2
	echo "Error: Missing required environment variables, aborting..." >&2
	echo "Error: This script should only be invoked by the CI Server" >&2
	exit 1
fi

# Abort if there are no documentation files
if [ ! -d "html" ] || [ ! -f "html/index.html" ]; then
	echo "" >&2
	echo "Error: No documentation (html) files have been found!" >&2
	echo "Error: Not going to push the documentation to GitHub!" >&2
	exit 1
fi

# Clone current gh-pages branch
git clone -b gh-pages https://git@${GH_REPO_REF}
cd ${GH_REPO_NAME}

# Configure git
git config --global push.default simple
git config user.name "Travis CI"
git config user.email "travis@travis-ci.org"

# Clean up working directory
CURRENTCOMMIT=`git rev-parse HEAD`
git reset --hard `git rev-list HEAD | tail -n 1`
git reset --soft $CURRENTCOMMIT

# Commit docs
mv ../html/* .
git add --all
git commit -m "Deploy docs for commit ${TRAVIS_COMMIT}"
git push --force "https://${GH_REPO_TOKEN}@${GH_REPO_REF}" > /dev/null 2>&1
echo "Docs have been published."
