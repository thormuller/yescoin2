// Copyright (c) 2011-2014 The Yescoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef YESCOINADDRESSVALIDATOR_H
#define YESCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class YescoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit YescoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Yescoin address widget validator, checks for a valid yescoin address.
 */
class YescoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit YescoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // YESCOINADDRESSVALIDATOR_H
