#!/bin/sh

git filter-branch -f --env-filter "GIT_AUTHOR_NAME='June'; GIT_AUTHOR_EMAIL='khsj15@khu.ac.kr'; GIT_COMMITTER_NAME='June'; GIT_COMMITTER_EMAIL='khsj15@khu.ac.kr';" HEAD

