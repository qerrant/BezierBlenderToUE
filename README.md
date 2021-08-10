# BezierBlenderToUE
Export Bezier curve from Blender to Unreal Engine 4

## List
* **ExportBezierToUE.py** - Blender add-on
* **Spline** - Unreal Engine project
* **TestSpline.csv** - Test file

## Guide
1. Install add-on in Blender:
  Edit -> Preferences... -> Add-ons -> Install (ExportBezierToUE.py)
2. Export Bezier curve points into CSV:
  Select object and File -> Export -> Export BezierCSV for UE4
3. Import CSV such as DataTable in Unreal Engine
4. Select DataTable in SplineActor
