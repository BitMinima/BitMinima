// Copyright (c) 2009-2014 The Bitcoin Core developers
// Copyright (c) 2017 The BitMinima Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("bitminima://16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("bitminima:16tJynQW1kQQeELfdT1FfqvGVixcbMhFLh?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
