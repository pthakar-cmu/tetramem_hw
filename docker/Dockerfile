FROM ubuntu:24.04

ARG DOCKER_UID=1000
ARG DOCKER_GID=1000

SHELL ["/bin/bash", "-c"]

ENV DEBIAN_FRONTEND noninteractive
ENV DISPLAY :10

# Install Libs
RUN apt-get -y update && \
    apt-get -y upgrade && \
    apt-get install --no-install-recommends -y cmake \
    dos2unix \
    file \
    g++ \
    gcc \
    gdb \
    git \
    libasound2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcursor-dev \
    libxinerama-dev \
    libwayland-dev \
    libxkbcommon-dev \
    linux-tools-generic \
    make \
    nano \
    ninja-build \
    python3-dev \
    python3-pip \
    python3-setuptools \
    python-is-python3 \
    sudo \
    vim 

#Install Raylib
RUN git clone https://github.com/raysan5/raylib.git raylib && \
    cd raylib && \
    mkdir build && cd build && \
    cmake -DBUILD_SHARED_LIBS=ON .. && \
    make && \
    make install && \
    ldconfig

#Setting up Workdir
WORKDIR /workdir