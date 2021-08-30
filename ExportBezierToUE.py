bl_info = {
    "name": "Export BezierCSV for UE4",
    "blender": (2, 80, 0),
    "author": "Alex Z.",
    "location": "File > Export > BezierCSV For UE (.csv)",
    "category": "Import-Export",
}

import sys, getopt
import os
import bpy
from bpy_extras.io_utils import ImportHelper


class ObjectExportPoints(bpy.types.Operator, ImportHelper):
    bl_idname = "me.export_bezier_points" 
    bl_label = "Export BezierCSV to UE4"   
    bl_options = {'REGISTER'} 
    
    def execute(self, context):
        obj = bpy.context.active_object
        objType = bpy.context.object.type
        
        if objType == 'CURVE':
            beziers = []
                        
            for subcurve in obj.data.splines:
                if subcurve.type == 'BEZIER':
                    beziers.append(subcurve)

            if len(beziers) > 0:        
                count = 1
                saveFile = open(self.filepath + ".csv", "w")
                saveFile.write("name,px,py,pz,hlx,hly,hlz,hrx,hry,hrz\n");
                str = '%d,%f,%f,%f,%f,%f,%f,%f,%f,%f\n'
            
                for bezier in beziers:
                    for point in bezier.bezier_points:
                        line = str % (count, \
                            point.co.x, -point.co.y, point.co.z, \
                            point.handle_left.x, -point.handle_left.y, point.handle_left.z, \
                            point.handle_right.x, -point.handle_right.y, point.handle_right.z)
                        saveFile.write(line);
                        count = count + 1
            
                saveFile.close()
                self.report({"INFO"}, "The curve was exported")
                return {'FINISHED'}
            else:
                self.report({"WARNING"}, "Selected object isn't a Bezier curve")
                return {'CANCELLED'}                
                
        else:
            self.report({"WARNING"}, "Selected object isn't a curve")
            return {'CANCELLED'}

def menu_func(self, context):
    self.layout.operator(ObjectExportPoints.bl_idname,text="Export BezierCSV For UE4 (.csv)")

def register():
    bpy.utils.register_class(ObjectExportPoints)
    bpy.types.TOPBAR_MT_file_export.append(menu_func)

def unregister():
    bpy.utils.unregister_class(ObjectExportPoints)
    bpy.types.TOPBAR_MT_file_export.remove(menu_func)

if __name__ == "__main__":
    register()
