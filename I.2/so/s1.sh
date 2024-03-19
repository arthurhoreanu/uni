if [ $# -lt 1 ]
then
	echo "param!!!"
	exit 1
fi
if [ ! -d $1 ]
then
	echo "nicht dir!"
	exit 2
fi
c=0
for f in `ls $1`
do
	echo "in for ... $f"
	if [ -e "$1/$f" -a  ! -d "$1/$f" ]
	then
		c=`expr $c + 1`
	fi		
done
echo "Anzahl: $c"
