#!/bin/bash

# set following environment variables before running this script:
# export JENKINS_URL=http://localhost:8080
# export TOKEN=your_api_token
# export BUILD_SERVER=your_build_server_ip
# export USER=your_ssh_user
# export PROJECT=c2


commit_message=${1:?"Commit message is required as the first argument."}

git add .
git commit -m "$commit_message"
git push -u origin HEAD

# refactor this curl to use post data instead of query parameters for better security and readability
curl -X POST "${JENKINS_URL}/job/cpp-template-fun-udemy/buildWithParameters" \
  -u "admin:${TOKEN}" \
  --data "build-server=${BUILD_SERVER}" \
  --data "user=${USER}" \
  --data "project=${PROJECT}"

echo "Triggered Jenkins build for project ${PROJECT} on build server ${BUILD_SERVER} with user ${USER}."