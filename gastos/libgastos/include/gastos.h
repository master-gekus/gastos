#ifndef GASTOS_GLOBAL_H
#define GASTOS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GASTOS_LIBRARY_INSOURCE)
# define GASTOSSHARED_EXPORT
#else
# if defined(GASTOS_LIBRARY)
#   define GASTOSSHARED_EXPORT Q_DECL_EXPORT
# else
#   define GASTOSSHARED_EXPORT Q_DECL_IMPORT
# endif
#endif

#endif // GASTOS_GLOBAL_H
