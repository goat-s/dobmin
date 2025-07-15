#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QPixmap>
#include <QColor>
#include <QPalette>

#define THEME ThemeManager::instance()

class ThemeManager : public QObject
{
    Q_OBJECT

    static ThemeManager * m_instance;

    QString m_defaultStyle;
    QPalette m_defaultPalette;

public:
    static ThemeManager *instance(QObject *mainwindow = nullptr);

signals:
    void styleApplied();

private:
    // 只允许单例实例
    ThemeManager();
    void apply();
};

#endif // THEMEMANAGER_H