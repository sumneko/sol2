// The MIT License (MIT)

// Copyright (c) 2013-2016 Rapptz and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STATE_HPP
#define SOL_STATE_HPP

#include "state_view.hpp"

namespace sol {
class state : private std::unique_ptr<lua_State, void(*)(lua_State*)>, public state_view {
private:
    typedef std::unique_ptr<lua_State, void(*)(lua_State*)> unique_base;
public:
    using state_view::get;
    state(lua_CFunction panic = detail::atpanic):
    unique_base(luaL_newstate(), lua_close),
    state_view(unique_base::get()) {
        set_panic(panic);
    }
};
} // sol

#endif // SOL_STATE_HPP
