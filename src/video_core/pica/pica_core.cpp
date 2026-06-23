*** Begin Patch
*** Update File: src/video_core/pica/pica_core.cpp
@@
-    const bool accelerate_draw = [this] {
-        // Geometry shaders cannot be accelerated due to register preservation.
-        if (regs.internal.pipeline.use_gs == PipelineRegs::UseGS::Yes) {
-            return false;
-        }
+    const bool accelerate_draw = [this] {
+        // Geometry shaders cannot be accelerated due to register preservation.
+        // If the user has disabled geometry shaders via settings, treat the pipeline as
+        // if it does not use GS for acceleration decisions. This does not remove the
+        // guest's GS codepath; it only allows acceleration when the user opted in.
+        if (regs.internal.pipeline.use_gs == PipelineRegs::UseGS::Yes &&
+            !Settings::values.disable_geometry_shaders.GetValue()) {
+            return false;
+        }
*** End Patch
