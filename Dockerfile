FROM gcc:latest

RUN apt-get update && apt-get install -y cmake

WORKDIR /app

COPY . /app

RUN mkdir build

WORKDIR /app/build

RUN cmake .. && make

CMD  ["./GrayScottSim"]