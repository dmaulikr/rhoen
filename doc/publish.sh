#!/bin/sh

# The following environment variables must be set:
# - GH_REPO_NAME        : The name of the repository.
# - GH_REPO_REF         : The GitHub reference to the repository.
# - GH_REPO_TOKEN       : Secure token to the github repository.
# - TRAVIS_BUILD_NUMBER : The number of the current build.
# - TRAVIS_COMMIT       : The commit that the current build is testing.

set -e
cd `dirname $0`

# Abort if required environment variables are not set
if [ -z ${GH_REPO_NAME} ] || [ -z ${GH_REPO_REF} ] || [ -z ${GH_REPO_TOKEN} ] ||
   [ -z ${TRAVIS_BUILD_NUMBER} ] || [ -z ${TRAVIS_COMMIT} ]; then
	echo "" >&2
	echo "Error: Missing required environment variables, aborting..."
	echo "Error: This script should only be invoked by the CI Server"
	exit 1
fi

# Abort if there are no documentation files
if [ ! -d "html" ] || [ ! -f "html/index.html" ]; then
	echo "" >&2
	echo "Error: No documentation (html) files have been found!" >&2
	echo "Error: Not going to push the documentation to GitHub!" >&2
	exit 1
fi

# Clone current docs branch
git clone -b gh-pages https://git@${GH_REPO_REF}
cd ${GH_REPO_NAME}

# Configure git using fake credentials
git config --global push.default simple
git config user.name "Travis CI"
git config user.email "travis@travis-ci.org"

# Clean up working directory
CURRENTCOMMIT=`git rev-parse HEAD`
git reset --hard `git rev-list HEAD | tail -n 1`
git reset --soft $CURRENTCOMMIT

# Publish
mv ../html/* .
git add --all
git commit -m "Deploy docs for Travis build: ${TRAVIS_BUILD_NUMBER}" -m "Commit: ${TRAVIS_COMMIT}"
git push --force "https://${GH_REPO_TOKEN}@${GH_REPO_REF}" > /dev/null 2>&1
echo "Done! Docs have been published."
