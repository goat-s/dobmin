# WorkXP 精简版

这是WorkXP的精简版本，只包含主窗口、工作区和缩放调整功能。

## 项目结构

- `main_minimal.cpp`: 程序入口点
- `mainwindow.cpp/h/ui`: 主窗口实现
- `workspace.cpp/h`: 工作区实现
- `basespace.cpp/h`: 基础图形视图实现
- `zoomadjust.cpp/h/ui`: 缩放调整控件实现
- `rulebar.cpp/h`: 标尺实现
- `wsplitter.cpp/h`: 分割器实现
- `svgdocument.cpp/h`: SVG文档实现
- `preferences.cpp/h`: 偏好设置实现
- `thememanager_minimal.cpp/h`: 主题管理器精简实现
- `commondef.h`: 通用定义
- `utilities.cpp/h`: 工具函数
- `graphicsitemtype.h`: 图形项类型定义

## 依赖库

- QtAwesome: 用于图标显示
- QtMaterialWidgets: 用于Material Design风格的控件

## 如何编译

1. 确保已安装Qt 5.12或更高版本
2. 打开Qt Creator
3. 打开`workxp_minimal.pro`文件
4. 点击构建按钮

## 功能

- 显示主窗口
- 显示工作区
- 支持缩放调整
- 显示标尺"# workxp_minimal" 
