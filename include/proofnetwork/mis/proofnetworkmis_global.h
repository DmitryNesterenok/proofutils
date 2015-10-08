#ifndef PROOFNETWORKMIS_GLOBAL_H
#define PROOFNETWORKMIS_GLOBAL_H

#ifdef PROOF_NETWORK_MIS_LIB
#  define PROOF_NETWORK_MIS_EXPORT Q_DECL_EXPORT
#else
#  define PROOF_NETWORK_MIS_EXPORT Q_DECL_IMPORT
#endif

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(proofNetworkMisDataLog)

#endif // PROOFNETWORKMIS_GLOBAL_H
