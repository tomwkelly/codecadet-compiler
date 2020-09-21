FROM ubuntu:focal

LABEL maintainer="Tom Kelly" \
      description="Language compiler for CodeCadet to WebAssembly." \
      version="0.1.0"

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/London
RUN apt-get update -y && \
    apt-get install -y tzdata

RUN apt-get install -y --no-install-recommends\
      git \
      curl \
      gcc-10 \
      g++ \
      build-essential \
      cmake \
      unzip \
      tar \
      ca-certificates && \
    apt-get autoclean && \
    apt-get autoremove && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
