#ifndef PROOF_UTILS_LABELPRINTER_H
#define PROOF_UTILS_LABELPRINTER_H

#include "proofcore/proofobject.h"
#include "proofutils_global.h"

namespace Proof {

class LabelPrinterPrivate;

struct LabelPrinterParams
{
    LabelPrinterParams() {}

    LabelPrinterParams(const QString &printerTitle, const QString &printerHost, const QString &printerName, int printerPort = 8090,
                       bool forceServiceUsage = false, bool strictHardwareCheck = true)
        : printerTitle(printerTitle),  printerHost(printerHost), printerName(printerName), printerPort(printerPort),
          forceServiceUsage(forceServiceUsage), strictHardwareCheck(strictHardwareCheck) {}

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
    ~LabelPrinter();

    bool printLabel(const QByteArray &label, bool ignorePrinterState = false);
    bool printerIsReady();

signals:
    void errorOccurred(long moduleCode, long errorCode, const QString &errorMessage, bool userFriendly);
};

} // namespace Proof

#endif // PROOF_UTILS_LABELPRINTER_H