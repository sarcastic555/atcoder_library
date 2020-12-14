#!/bin/zsh

docker run \
       -v ${DEVELOP_PATH}/atcoder_library/example_checker:/home/example_checker \
       -e TZ=Asia/Tokyo \
       -it \
       --rm \
       example_checker
