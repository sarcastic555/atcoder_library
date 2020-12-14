#!/bin/zsh

docker run \
       -v ${DEVELOP_PATH}/atcoder_library:/home/atcoder_library \
       -e TZ=Asia/Tokyo \
       -it \
       --rm \
       atcoder_library
