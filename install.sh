echo 'git clone https://github.com/${REPO} ${GLD_SRC}/module/${NAME} -b ${BRANCH:-main} --depth 1;cd ${GLD_SRC}/module/${NAME}/source;make install' | gridlabd shell
