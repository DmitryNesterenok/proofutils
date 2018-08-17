#ifndef PROOFUTILS_BASIC_PACKAGE_H
#define PROOFUTILS_BASIC_PACKAGE_H

#include "proofcore/coreapplication.h"
#include "proofcore/future.h"
#include "proofcore/proofalgorithms.h"
#include "proofcore/proofobject.h"
#include "proofcore/settings.h"
#include "proofcore/settingsgroup.h"
#include "proofcore/tasks.h"

#include "proofnetwork/apicall.h"

using Proof::ProofObject;

namespace algorithms = Proof::algorithms;

using Proof::CancelableFuture;
using Proof::Failure;
using Proof::Future;
using Proof::FutureSP;
using Proof::FutureWP;
using Proof::Promise;
using Proof::PromiseSP;
using Proof::PromiseWP;
using Proof::WithFailure;

namespace tasks = Proof::tasks;

using Proof::Settings;
using Proof::SettingsGroup;

using Proof::ApiCall;

#endif // PROOFUTILS_BASIC_PACKAGE_H
