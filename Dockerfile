FROM sbtscala/scala-sbt:eclipse-temurin-jammy-17.0.9_9_1.9.8_2.13.12 as scala-builder

RUN apt-get update && apt-get install -y --no-install-recommends \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY ./scala /app
RUN make build

FROM ubuntu:jammy

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ make \
    && rm -rf /var/lib/apt/lists/*

COPY --from=scala-builder /app/target /app/scala/target
COPY ./cpp /app/cpp
WORKDIR /app/cpp

RUN make runner
