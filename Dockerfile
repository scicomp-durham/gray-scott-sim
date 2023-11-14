FROM gcc:latest AS build

RUN apt-get update && apt-get install -y cmake

WORKDIR /app

COPY . /app

RUN mkdir build

WORKDIR /app/build

RUN cmake .. && make

FROM debian:latest

WORKDIR /app

COPY --from=build /app/build/GrayScottSim /app

CMD  ["./GrayScottSim"]