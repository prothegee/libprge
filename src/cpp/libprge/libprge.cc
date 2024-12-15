#include "libprge.hh"

namespace libprge
{

void CLibPrGe::_bind_methods()
{
}

CLibPrGe::CLibPrGe()
{
    if (!m_pThis) { m_pThis = this; }

    libprge_initialize_pointers();
}

CLibPrGe::~CLibPrGe()
{
    if (m_pThis) { m_pThis = nullptr; }
}

} // namespace libprge
