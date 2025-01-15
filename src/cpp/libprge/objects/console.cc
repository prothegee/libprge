#include "console.hh"

namespace libprge
{

void console::_bind_methods()
{
    // base
    {
        ClassDB::bind_static_method(console_CLASS, D_METHOD("log", "arrayArgs"), &console::blog);
        ClassDB::bind_static_method(console_CLASS, D_METHOD("log_debug", "arrayArgs"), &console::blog_debug);

        ClassDB::bind_static_method(console_CLASS, D_METHOD("warning", "arrayArgs"), &console::bwarning);
        ClassDB::bind_static_method(console_CLASS, D_METHOD("warning_debug", "arrayArgs"), &console::bwarning_debug);

        ClassDB::bind_static_method(console_CLASS, D_METHOD("error", "arrayArgs"), &console::berror);
        ClassDB::bind_static_method(console_CLASS, D_METHOD("error_debug", "arrayArgs"), &console::berror_debug);
    }
}

console::console()
{
}

console::~console()
{
}

} // namespace libprge
