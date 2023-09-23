REPONAME=arras-energy/module_template
TOOLNAME=template
mkdir -p /usr/local/opt/gridlabd/current/src/module
git clone https://github.com/$REPONAME $TOOLNAME -b $BRANCH --depth 1
cd $TOOLNAME/source
echo "make install" | gridlabd shell
