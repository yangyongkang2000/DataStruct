Module[{ProvinceName = {Entity[
     "AdministrativeDivision", {"Hubei", "China"}], 
    Entity["AdministrativeDivision", {"Zhejiang", "China"}], 
    Entity["AdministrativeDivision", {"Guangdong", "China"}], 
    Entity["AdministrativeDivision", {"Hunan", "China"}], 
    Entity["AdministrativeDivision", {"Henan", "China"}], 
    Entity["AdministrativeDivision", {"Anhui", "China"}], 
    Entity["AdministrativeDivision", {"Chongqing", "China"}], 
    Entity["AdministrativeDivision", {"Shandong", "China"}], 
    Entity["AdministrativeDivision", {"Jiangxi", "China"}], 
    Entity["AdministrativeDivision", {"Sichuan", "China"}], 
    Entity["AdministrativeDivision", {"Jiangsu", "China"}], 
    Entity["AdministrativeDivision", {"Beijing", "China"}], 
    Entity["AdministrativeDivision", {"Fujian", "China"}], 
    Entity["AdministrativeDivision", {"Shanghai", "China"}], 
    Entity["AdministrativeDivision", {"Guangxi", "China"}], 
    Entity["AdministrativeDivision", {"Shaanxi", "China"}], 
    Entity["AdministrativeDivision", {"Hebei", "China"}], 
    Entity["AdministrativeDivision", {"Yunnan", "China"}], 
    Entity["AdministrativeDivision", {"Hainan", "China"}], 
    Entity["AdministrativeDivision", {"Heilongjiang", "China"}], 
    Entity["AdministrativeDivision", {"Liaoning", "China"}], 
    Entity["AdministrativeDivision", {"Shanxi", "China"}], 
    Entity["AdministrativeDivision", {"Tianjin", "China"}], 
    Entity["AdministrativeDivision", {"Gansu", "China"}], 
    Entity["AdministrativeDivision", {"Neimenggu", "China"}], 
    Entity["AdministrativeDivision", {"Xinjiang", "China"}], 
    Entity["AdministrativeDivision", {"Ningxia", "China"}], 
    Entity["AdministrativeDivision", {"Guizhou", "China"}], 
    Entity["AdministrativeDivision", {"Jilin", "China"}], 
    Entity["Country", "Taiwan"], 
    Entity["City", {"HongKong", "HongKong", "HongKong"}], 
    Entity["Country", "Macau"], 
    Entity["AdministrativeDivision", {"Qinghai", "China"}], 
    Entity["AdministrativeDivision", {"Xizang", "China"}]},ProvinceMaxTemperature,association,temperaturedate},
     ProvinceMaxTemperature = 
  Table[WeatherData[ProvinceName[[n]]["Position"], 
    "MaxTemperature", {{2020, 4, 1}, {2020, 5, 6}, "Day"}], {n, 1, 
    34}];association = AssociationThread[ProvinceName, ProvinceMaxTemperature];
    temperaturedate = ((Normal@#)[[All, 2]]) & /@ ProvinceMaxTemperature;
    Export["近一个月全国气温变化.gif", 
 ListAnimate[GeoRegionValuePlot[
    AssociationThread[ProvinceName, 
     Function[index, Part[#, index] & /@ temperaturedate][#]]] & /@ 
  Range[30]]];
      Export["近一个月全国气温变化气泡.gif", 
 ListAnimate[GeoBubbleChart[
    AssociationThread[ProvinceName, 
     Function[index, Part[#, index] & /@ temperaturedate][#]]] & /@ 
  Range[30]]];
  DateListPlot[AssociationThread[ProvinceName, ProvinceMaxTemperature]]
    ]