// Copyright 2010 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.

// This code was generated by google-apis-code-generator 1.5.0
//   Build date: 2014-10-28 17:08:27 UTC
//   on: 2014-10-30, 17:11:04 UTC
//   C++ generator version:

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Drive API (drive/v2)
// Description:
//   The API to interact with Drive.
// Classes:
//   PermissionList
// Documentation:
//   https://developers.google.com/drive/

#include "google/drive_api/permission_list.h"
#include <string>
#include "googleapis/client/data/jsoncpp_data.h"
#include "googleapis/strings/stringpiece.h"

#include "google/drive_api/permission.h"


#include <string>
#include "googleapis/strings/strcat.h"

namespace google_drive_api {
using namespace googleapis;


// Object factory method (static).
PermissionList* PermissionList::New() {
  return new client::JsonCppCapsule<PermissionList>;
}

// Standard immutable constructor.
PermissionList::PermissionList(const Json::Value& storage)
  : client::JsonCppData(storage) {
}

// Standard mutable constructor.
PermissionList::PermissionList(Json::Value* storage)
  : client::JsonCppData(storage) {
}

// Standard destructor.
PermissionList::~PermissionList() {
}
}  // namespace google_drive_api
