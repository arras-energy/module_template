mkdir -p /usr/local/opt/gridlabd/current/src/module
git clone https://github.com/$REPO $NAME -b $BRANCH --depth 1
cd $NAME/source
echo "make install" | gridlabd shell
