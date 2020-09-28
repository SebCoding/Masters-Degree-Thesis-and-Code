#!/bin/sh

# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# * This source file is part of SableVM.                            *
# *                                                                 *
# * See the file "LICENSE" for the copyright information and for    *
# * the terms and conditions for copying, distribution and          *
# * modification of this source file.                               *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

set -e

aclocal
libtoolize --force
autoconf
autoheader
automake --foreign -a -c

for one in `cd src; ls`; do
  if [ -x src/$one/autogen.sh ]; then
    echo
    echo "*** Will run src/$one/autogen.sh"
    cd src/$one; ./autogen.sh; cd ../..
  fi
done

#echo "You can now run ./configure."
