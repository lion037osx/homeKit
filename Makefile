init:

	echo "# homeKit" >> README.md
	git init
	git add README.md
	git commit -m "first commit"
	git remote add origin https://github.com/lion037osx/qtHomeKit.git
	git push -u origin master


existing:

	git remote add origin https://github.com/lion037osx/qtHomeKit.git
	git push -u origin master

clean:

	rm -R .git
	rm README*


help:
	@+echo ""
	@+echo ""
	@+echo "*********************************Help GIT******************************************"
	@+echo ""
	@+echo "make clone"
	@+echo "		git clone https://github.com/lion037osx/qtHomeKit.git"
	@+echo "make push"
	@+echo "		git push https://github.com/lion037osx/qtHomeKit.git"
	@+echo "make pull"
	@+echo "		git pull https://github.com/lion037osx/qtHomeKit.git"
	@+echo "make commit"
	@+echo "		git commit -m \"update\""
	@+echo "make add"
	@+echo "		git add ."
	@+echo "		git commit - m \"update\""
	@+echo "		git push origin master"
	@+echo ""
	@+echo ""
	@+echo "		Copyrigth by Leo"
	@+echo ""
	@+echo ""


clone:

	git clone https://github.com/lion037osx/qtHomeKit.git


push:
	git add.
	git commit -m "update push"
#	git push origin master 
	git push https://github.com/lion037osx/qtHomeKit.git

pull:
	git add .
	git commit -m "upgrade pull"
#	git pull origin master
	git pull git push https://github.com/lion037osx/qtHomeKit.git

upgrade:
	git add .
	git commit -m "push origin master"
	git push origin master






