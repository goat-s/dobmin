#include "thememanager_minimal.h"
#include "QtAwesome/QtAwesome.h"
#include "preferences.h"
#include "commondef.h"

#include <QApplication>
#include <QStyleFactory>
#include <QStyle>

ThemeManager * ThemeManager::m_instance = 0;

ThemeManager *ThemeManager::instance(QObject *mainwindow)
{
    if (!m_instance) {
        m_instance = new ThemeManager();
        if (mainwindow) {
            m_instance->setParent(mainwindow);
        }
    }
    return m_instance;
}

ThemeManager::ThemeManager()
{
    m_defaultStyle = QApplication::style()->objectName();
    m_defaultPalette = QApplication::palette();
    apply();
}

void ThemeManager::apply()
{
    // 应用主题样式
    int style = Preferences::instance()->style();
    if (style == THEME_DARKEN) {
        QApplication::setStyle(QStyleFactory::create("Fusion"));
    } else {
        QApplication::setStyle(QStyleFactory::create("Fusion"));
    }
    
    emit styleApplied();
}