FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
        libeigen3-dev \
        libyaml-cpp-dev \
        libboost-test-dev \
        && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /app

CMD ["bash"]