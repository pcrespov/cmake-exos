# Development image
FROM alpine AS builder-stage
#FROM ubuntu:latest AS builder-stage
LABEL builder=true

#RUN apt-get update
#RUN apt-get install -y \
#  gcc \
#  cmake \
#  libboost-all-dev \
#  g++ `#Fb folly deps`

RUN apk update && \
    apk upgrade && \
    apk --update add \
          gcc \
          g++ \
          build-base \
          cmake \
          bash \
          libstdc++ && \
    rm -rf /var/cache/apk/*

WORKDIR /src

# Copy source code in /src
COPY . .

# Build code with cmake
RUN mkdir build && cd build && cmake .. && make

# Deploy image ---
FROM alpine AS app-stage
# Removes label docker images --filter "label=builder=true" --format '{{.CreatedAt}}\t{{.ID}}' | sort -nr | head -n 1 | cut -f2
LABEL builder=false

WORKDIR /app

COPY --from=builder-stage /src/build/tutorial .
COPY --from=builder-stage /usr/lib/*.so* /usr/lib/

CMD [ "./tutorial" ]
