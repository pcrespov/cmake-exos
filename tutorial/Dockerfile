# Development image
FROM ubuntu:latest AS builder

RUN apt-get update
RUN apt-get install -y \
  gcc \
  cmake \
  libboost-all-dev \
  g++ `#Fb folly deps`

WORKDIR /src

# Copy source code in /src
COPY . .

# Build code with cmake
RUN mkdir build && cd build && cmake .. && make

# Deploy image ---
FROM alpine

WORKDIR /app

COPY --from=builder /src/build/tutorial .
#COPY --from=builder /libs/ /libs/

CMD [ "./tutorial" ]
