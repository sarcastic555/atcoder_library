FROM ubuntu:20.04
USER root

# to install tzdata noninteractively
ENV DEBIAN_FRONTEND=noninteractive

# Python environment
RUN apt-get update && \
    apt-get -y install python3.8 python3-pip && \
    apt-get update

# Useful
RUN apt-get update && \
    apt-get -y install less tzdata git rsync && \
    apt-get update

# Use python3.8 when python3 is called
RUN update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 1
RUN update-alternatives --set python3 /usr/bin/python3.8
RUN python3 -m pip install -U pip
RUN ln -s /usr/bin/python3 /usr/bin/python

# install python library
COPY requirements.txt /tmp/
RUN pip install -r /tmp/requirements.txt


# Environmental variable definition
ENV LANG ja_JP.UTF-8
ENV LESSCHARSET utf-8

WORKDIR /home/atcoder_library
