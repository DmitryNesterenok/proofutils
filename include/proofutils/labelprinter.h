/* Copyright 2018, OpenSoft Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials provided
 * with the distribution.
 *     * Neither the name of OpenSoft Inc. nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef PROOF_UTILS_LABELPRINTER_H
#define PROOF_UTILS_LABELPRINTER_H

#include "proofseed/asynqro_extra.h"

#include "proofcore/proofobject.h"

#include "proofutils/proofutils_global.h"

namespace Proof {
class LabelPrinterPrivate;
struct LabelPrinterParams
{
    LabelPrinterParams() {}

    LabelPrinterParams(const QString &printerTitle, const QString &printerHost, const QString &printerName,
                       int printerPort = 8090, bool forceServiceUsage = false, bool strictHardwareCheck = true)
        : printerTitle(printerTitle), printerHost(printerHost), printerName(printerName), printerPort(printerPort),
          forceServiceUsage(forceServiceUsage), strictHardwareCheck(strictHardwareCheck)
    {}

    QString printerTitle;
    QString printerHost;
    QString printerName;
    int printerPort = 0;
    bool forceServiceUsage = false;
    bool strictHardwareCheck = true;
};

class PROOF_UTILS_EXPORT LabelPrinter : public ProofObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(LabelPrinter)
public:
    explicit LabelPrinter(const LabelPrinterParams &params, QObject *parent = nullptr);
    LabelPrinter(const LabelPrinter &other) = delete;
    LabelPrinter &operator=(const LabelPrinter &other) = delete;
    LabelPrinter(LabelPrinter &&other) = delete;
    LabelPrinter &operator=(LabelPrinter &&other) = delete;
    ~LabelPrinter();

    Future<bool> printLabel(const QByteArray &label, bool ignorePrinterState = false) const;
    Future<bool> printerIsReady() const;
    QString title() const;
};

} // namespace Proof

#endif // PROOF_UTILS_LABELPRINTER_H
