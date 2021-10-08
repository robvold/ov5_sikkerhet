FROM ubuntu:latest as base


# installing requirements to get and extract prebuilt binaries
RUN apt-get update && apt-get install -y \
 llvm \
 clang \
 cmake \
 protobuf-compiler \
 && rm -rf /var/lib/apt/lists/*

COPY . /ov5_sikkerhet
WORKDIR /ov5_sikkerhet/build
RUN CC=clang cmake ..
RUN make
RUN ./tests/utility_fuzzer_test -max_total_time=60
