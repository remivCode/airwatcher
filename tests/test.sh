echo "-----------------------------------------------------------"

execDir=$(pwd)
echo "Execution Directory: $execDir"

if [ "$1" = "" ]
then
  echo "No directory given, default to current"
  Directory="."
else  
  echo "| Test id : $1"
  if [ -d "$1" ]
  then 
     Directory="$1"
  else
     echo "$1 is not a directory. Exiting."
     exit 2
  fi
fi

cd $Directory || { echo "Failed to change directory to $Directory. Exiting."; exit 2; }
echo "Changed to directory: $(pwd)"

if [ -r "description" ]
then 
  echo "-----------------------------------------------------------"
  echo "Description :"
  fold description -w 60 -s
  echo
  echo "-----------------------------------------------------------"
fi

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

if [ -r "run" ]
then
  sRun=$(cat run)
else
  echo "No run file found. Exiting."
  exit 2
fi

# stdin has been specified
if [ -r "std.in" ]
then
  echo "std.in found"
  sRun="$sRun < std.in"
else
  echo "std.in not found in $(pwd)"
fi


# stdout has been specified
if [ -r "std.out" ]
then 
  echo "std.out found"
  sRun="$sRun > temp.txt"
else
  echo "std.out not found in $(pwd)"
fi

echo "Command to execute: $sRun"
# execute the command line
eval "$sRun"
returnCode=$?

resultGlobal=1

# compare stdout if concerned
resultOut=2
if [ -r "std.out" ]
then 
  diff -wB temp.txt std.out >/dev/null
  if [ $? -eq 0 ]
  then
    echo "                                       Stdout      : PASSED"
    resultOut=1
  else
    echo "                                       Stdout      : FAILED"
    resultOut=0
    resultGlobal=0
    diff -wB -y --side-by-side  temp.txt std.out 
  fi
  # clean temporary out file
  rm temp.txt
fi

echo "                                       --------------------"
if [ $resultGlobal -eq 0 ]
then
  echo "                                       Global      : FAILED"
else
  echo "                                       Global      : PASSED"
fi
echo "-----------------------------------------------------------"
echo 
echo
echo

cd "$execDir" || { echo "Failed to change back to $execDir. Exiting."; exit 2; }

# log result in $2 if filename provided
if [ "$2" != "" ]
then
  if [ ! -w "$2" ]
  then
    touch $2
  fi
  if [ -w "$2" ]
  then
    echo "$Directory;$resultOut;$resultGlobal" >> "$2"
  fi
fi

exit $resultGlobal

