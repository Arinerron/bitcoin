#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

JOBECOIND=${JOBECOIND:-$SRCDIR/jobecoind}
JOBECOINCLI=${JOBECOINCLI:-$SRCDIR/jobecoin-cli}
JOBECOINTX=${JOBECOINTX:-$SRCDIR/jobecoin-tx}
JOBECOINQT=${JOBECOINQT:-$SRCDIR/qt/jobecoin-qt}

[ ! -x $JOBECOIND ] && echo "$JOBECOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($JOBECOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for jobecoind if --version-string is not set,
# but has different outcomes for jobecoin-qt and jobecoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$JOBECOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $JOBECOIND $JOBECOINCLI $JOBECOINTX $JOBECOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
