// bson_util.h

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include "../pch.h"

namespace mongo {

template <typename T>
void bsonArrToNumVector(BSONElement el, vector<T>& results){

    if(el.type() == Array){

	vector<BSONElement> elements = el.Array();

        for(vector<BSONElement>::iterator i = elements.begin(); i != elements.end(); ++i){
            results.push_back( (T) (*i).Number() );
        }
    }
    else if(el.isNumber()){
	results.push_back( (T) el.Number() );
    }

}


}