// Copyright (c) 2011-2014 The Jobecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef JOBECOIN_QT_JOBECOINADDRESSVALIDATOR_H
#define JOBECOIN_QT_JOBECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class JobecoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit JobecoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Jobecoin address widget validator, checks for a valid jobecoin address.
 */
class JobecoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit JobecoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // JOBECOIN_QT_JOBECOINADDRESSVALIDATOR_H
