FROM ubuntu:latest as base


# installing requirements to get and extract prebuilt binaries
RUN apt-get update && apt-get install -y llvm clang cmake

COPY . /ov5_sikkerhet
RUN rm -r /ov5_sikkerhet/build
RUN mkdir /ov5_sikkerhet/build
WORKDIR /ov5_sikkerhet/build
RUN CC=clang cmake ..
RUN make
RUN ./tests/utility_fuzzer_test -max_total_time=60
