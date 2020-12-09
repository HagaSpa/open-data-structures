FROM gcc:10.2.0

RUN apt update && apt install -y gdb

WORKDIR /workspace