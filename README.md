# cmake-exos
Exercises with cmake


### Build & deploy using the same Dockerfile
 - Created a dockerfile with a multi-stage build to both perform the build and ships a container with
 only the resulting artifacts!!

 ```bash
 cd tutorial
 docker build -t pcrespov/tutorial .

 # Deploys a tiny image!
 docker image ls -f 'label=builder'
 docker run pcrespov/tutorial ls -la

 # Executes tutorial
 docker run pcrespov/tutorial:v1
 ```

Another option bind mount ```src``` and ```build``` to the host and use
```bash
cd tutorial
docker run -it -v $(pwd):/src -v $(pwd)/build:/build pcrespov/cppenv /bin/bash
```

Useful references:
 - Docker dev best practices : https://docs.docker.com/develop/dev-best-practices/
 - Official Doc: https://docs.docker.com/engine/userguide/eng-image/multistage-build/
 - Multi-stage build with C++: https://imantabrizian.me/blog/docker-multistage-builds/
 - Builder pattern vs multi-stage build: https://blog.alexellis.io/mutli-stage-docker-builds/
 -

 ~~ISSUE 1~~ : the last command does not run. tutorial must lack some library?==>c++ binaries built in ubuntu might not run in alpine. See [holly build box](https://github.com/phusion/holy-build-box). Solved creating an multistage-build that build  the code and deploys binaries using alpine.
