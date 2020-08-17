// Copyright © 2019-2020 Dmitriy Lukovenko. All rights reserved.
// Contacts: <mludima23@gmail.com>
// License: http://opensource.org/licenses/MIT

#pragma once

namespace ion
{
    template<typename ...TArgs>
    inline std::string format(const std::string& fmt, TArgs&& ...args)
    {
        int size = std::snprintf(nullptr, 0, fmt.c_str(), std::forward<TArgs>(args)...) + 1;

        if (size <= 0)
        {
            throw std::logic_error("Error during formatting");
        }

        std::unique_ptr<char[]> buffer = std::make_unique<char[]>(size);
        std::snprintf(buffer.get(), static_cast<size_t>(size), fmt.c_str(), std::forward<TArgs>(args)...);
        return std::string(buffer.get(), buffer.get() + size - 1);
    }
}
