#include "weatherwidget.h"

weatherWidget::weatherWidget(QWidget *parent) : QWidget(parent)
{
    initMemberVariables();
    initGSettingValue();
    initLabelData();
    initLayout();
}

void weatherWidget::initMemberVariables()
{
    m_pWeatherIconLabel = new QLabel();
    m_pWeatherIconLabel->setFixedSize(16, 16);

    m_pAreaLabel = new QLabel();
    m_pAreaLabel->setFixedHeight(18);

    QFont font = m_pAreaLabel->font();
    font.setPixelSize(12);
    m_pAreaLabel->setFont(font);

    QPalette palette = m_pAreaLabel->palette();
    QColor color(89, 89, 89, 255);
    palette.setBrush(QPalette::Text, color);
    m_pAreaLabel->setPalette(palette);

    m_pMainHLayout = new QHBoxLayout();
    m_pMainHLayout->setContentsMargins(0, 15, 0, 17);
    m_pMainHLayout->setSpacing(0);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void weatherWidget::initLabelData()
{
    QPixmap pixmap = QIcon::fromTheme("indicator-china-weather").pixmap(QSize(m_pWeatherIconLabel->size()));
    m_pWeatherIconLabel->setPixmap(pixmap);
    m_pweatherString = m_pWeatherGsetting->get(UKUI_WEATHER_GSETTING_KEY).toString();

    QStringList WeatherInfoList = m_pweatherString.split(",");
    setLabelData(WeatherInfoList);
    return;
}

void weatherWidget::setLabelData(QStringList WeatherInfoList)
{
    if (WeatherInfoList.count() <= 8) {
        return;
    }
    QString WeatherInfo = nullptr;
    if (WeatherInfoList.at(8) != WeatherInfoList.at(2))
        WeatherInfo = QStringLiteral("%1·%2 %3 %4").arg(WeatherInfoList.at(8)).arg(WeatherInfoList.at(2)) \
                .arg(WeatherInfoList.at(3)).arg(WeatherInfoList.at(5));
    else
        WeatherInfo = QStringLiteral("%1 %2 %3").arg(WeatherInfoList.at(2)) \
                .arg(WeatherInfoList.at(3)).arg(WeatherInfoList.at(5));
    qDebug() << WeatherInfo;
    m_pAreaLabel->setText(WeatherInfo);
    return;
}

void weatherWidget::initGSettingValue()
{
    /* 链接time-shutdown的dgsetting接口 */
    if (QGSettings::isSchemaInstalled(UKUI_WEATHER_GSETTING_ID))
        m_pWeatherGsetting = new QGSettings(UKUI_WEATHER_GSETTING_ID);
    if (m_pWeatherGsetting != nullptr) {
        qDebug() << "当前的gsetting的key值" << m_pWeatherGsetting->keys();
        connect(m_pWeatherGsetting, &QGSettings::changed, this, &weatherWidget::getGsettingChageSlots);
    }
    return;
}

void weatherWidget::initLayout()
{
    m_pMainHLayout->addItem(new QSpacerItem(32, 10));
    m_pMainHLayout->addWidget(m_pWeatherIconLabel);
    m_pMainHLayout->addItem(new QSpacerItem(2, 0));
    m_pMainHLayout->addWidget(m_pAreaLabel);
    m_pMainHLayout->addItem(new QSpacerItem(243, 10, QSizePolicy::Expanding));
    this->setLayout(m_pMainHLayout);
    return;
}

void weatherWidget::getGsettingChageSlots(QString key)
{
    if (key == UKUI_WEATHER_GSETTING_KEY) {
        m_pweatherString = m_pWeatherGsetting->get(UKUI_WEATHER_GSETTING_KEY).toString();
    }
    QStringList WeatherInfoList = m_pweatherString.split(",");
    setLabelData(WeatherInfoList);
    return;
}
