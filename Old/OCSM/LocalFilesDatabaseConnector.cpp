#include "OCSM/LocalFilesDatabaseConnector.h"
#include <QFile>
#include <QDir>
#include <QSettings>

namespace OCSM
{
	QString LocalFilesDatabaseConnector::m_root_path;
    QSettings* LocalFilesDatabaseConnector::m_settings = 0;

    void LocalFilesDatabaseConnector::SetRootPath(ConstQString& root_path)
    {
        m_root_path = root_path;

        if (m_settings != 0)
            delete m_settings;

        m_settings = new QSettings(m_root_path + "/Database/setting.ini", QSettings::IniFormat);
    }

	QString LocalFilesDatabaseConnector::GetName(int zone, int grid_row, int grid_col)
	{
        return QString::number(zone) + "-" + QString::number(grid_row) + "-" + QString::number(grid_col);
	}

	QString LocalFilesDatabaseConnector::GetFilePath(int zone, int grid_row, int grid_col)
	{
        return m_root_path + "/Database/" + QString::number(zone) + "/" + QString::number(grid_row) + "-" + QString::number(grid_col) + ".xodr";
	}

	QString LocalFilesDatabaseConnector::GetFilePath(Common::ConstVehiclePos& coord)
	{
		return GetFilePath(coord.zone, coord.grid_row, coord.grid_col);
	}

	bool LocalFilesDatabaseConnector::Exists(Common::ConstVehiclePos& coord)
	{
        return QFile(GetFilePath(coord)).exists();
	}

	OpenDRIVE::OpenDRIVE LocalFilesDatabaseConnector::Get(Common::ConstVehiclePos& coord)
	{
		QString file_path = GetFilePath(coord);
        OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
        return result;
	}

	OpenDRIVE::OpenDRIVE LocalFilesDatabaseConnector::GetNorth(Common::ConstVehiclePos& coord)
	{
		QString file_path = GetFilePath(coord.zone, coord.grid_row - 1, coord.grid_col);
        OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
        return result;
	}

	OpenDRIVE::OpenDRIVE LocalFilesDatabaseConnector::GetSouth(Common::ConstVehiclePos& coord)
	{
		QString file_path = GetFilePath(coord.zone, coord.grid_row + 1, coord.grid_col);
        OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
        return result;
	}

	OpenDRIVE::OpenDRIVE LocalFilesDatabaseConnector::GetEast(Common::ConstVehiclePos& coord)
	{
		QString file_path = GetFilePath(coord.zone, coord.grid_row, coord.grid_col - 1);
        OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
        return result;
	}

	OpenDRIVE::OpenDRIVE LocalFilesDatabaseConnector::GetWest(Common::ConstVehiclePos& coord)
	{
		QString file_path = GetFilePath(coord.zone, coord.grid_row, coord.grid_col + 1);
		OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
		return result;
	}

	void LocalFilesDatabaseConnector::Update(Common::ConstVehiclePos& coord, OpenDRIVE::OpenDRIVE& content)
	{
        QString file_dir = m_root_path + "/Database/" + QString::number(coord.zone);
        if (!QDir().mkpath(file_dir))
		{
            MyCout << "Directory creation failed: " << file_dir << MyEndl;
			return;
		}

		QString file_path = GetFilePath(coord);
        if (content.write(file_path))
		{
            MyCout << "Saving succeeded: " << file_path << MyEndl;
		}
		else
		{
            MyCout << "Saving failed: " << file_path << MyEndl;
		}

        m_settings->sync();
	}

}
