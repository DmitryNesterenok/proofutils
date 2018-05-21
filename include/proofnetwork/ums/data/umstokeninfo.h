#ifndef PROOF_UMS_UMSTOKENINFO_H
#define PROOF_UMS_UMSTOKENINFO_H

#include "proofnetwork/networkdataentity.h"
#include "proofnetwork/ums/proofnetworkums_types.h"
#include "proofnetwork/ums/proofnetworkums_global.h"
#include "proofnetwork/ums/data/qmlwrappers/umstokeninfoqmlwrapper.h"

namespace Proof {
namespace Ums {

class UmsTokenInfoPrivate;
class PROOF_NETWORK_UMS_EXPORT UmsTokenInfo : public NetworkDataEntity // clazy:exclude=ctor-missing-parent-argument
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(UmsTokenInfo)
public:
    ~UmsTokenInfo();

    QString version() const;
    QDateTime expiresAt() const;
    QDateTime validFrom() const;
    UmsUserSP user() const;
    QString token() const;

    UmsTokenInfoQmlWrapper *toQmlWrapper(QObject *parent = nullptr) const override;

    static UmsTokenInfoSP create();
    static UmsTokenInfoSP fromJson(const QJsonObject &tokenJson, const QString &token);

signals:
    void versionChanged(const QString &arg);
    void expiresAtChanged(const QDateTime &arg);
    void validFromChanged(const QDateTime &arg);
    void userChanged(const Proof::Ums::UmsUserSP &arg);
    void tokenChanged(const QString &arg);

protected:
    UmsTokenInfo();
};

} // namespace Ums
} // namespace Proof

#endif // PROOF_UMS_UMSTOKENINFO_H