# cmake-exos
Exercises with cmake


### Build & deploy using the same Dockerfile
 - Created a dockerfile with a multi-stage build to both perform the build and ships a container with
 only the resulting artifacts!!

 ```bash
 cd tutorial
 docker build -t pcrespov/tutorial:v1

 # Deploys a tiny image!
 docker image ls -la
 docker run pcrespov/tutorial:v1 ls -la

 # Executes tutorial
 docker run pcrespov/tutorial:v1
 ```

Another option is to use
```bash
docker run -it -v $(pwd):/src -v $(pwd)/build:/build pcrespov/cppenv /bin/bash
```

Useful references:
 - Docker dev best practices : https://docs.docker.com/develop/dev-best-practices/
 - Official Doc: https://docs.docker.com/engine/userguide/eng-image/multistage-build/
 - Multi-stage build with C++: https://imantabrizian.me/blog/docker-multistage-builds/
 - Builder pattern vs multi-stage build: https://blog.alexellis.io/mutli-stage-docker-builds/
 -
