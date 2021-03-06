
(cl:in-package :asdf)

(defsystem "cob_3d_mapping_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :cob_object_detection_msgs-msg
               :geometry_msgs-msg
               :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "TableObjectClusterAction" :depends-on ("_package_TableObjectClusterAction"))
    (:file "_package_TableObjectClusterAction" :depends-on ("_package"))
    (:file "TableObjectClusterResult" :depends-on ("_package_TableObjectClusterResult"))
    (:file "_package_TableObjectClusterResult" :depends-on ("_package"))
    (:file "TableObjectClusterActionFeedback" :depends-on ("_package_TableObjectClusterActionFeedback"))
    (:file "_package_TableObjectClusterActionFeedback" :depends-on ("_package"))
    (:file "TableObjectClusterFeedback" :depends-on ("_package_TableObjectClusterFeedback"))
    (:file "_package_TableObjectClusterFeedback" :depends-on ("_package"))
    (:file "TriggerAction" :depends-on ("_package_TriggerAction"))
    (:file "_package_TriggerAction" :depends-on ("_package"))
    (:file "TriggerFeedback" :depends-on ("_package_TriggerFeedback"))
    (:file "_package_TriggerFeedback" :depends-on ("_package"))
    (:file "PlaneExtractionActionGoal" :depends-on ("_package_PlaneExtractionActionGoal"))
    (:file "_package_PlaneExtractionActionGoal" :depends-on ("_package"))
    (:file "TriggerActionFeedback" :depends-on ("_package_TriggerActionFeedback"))
    (:file "_package_TriggerActionFeedback" :depends-on ("_package"))
    (:file "PlaneExtractionActionFeedback" :depends-on ("_package_PlaneExtractionActionFeedback"))
    (:file "_package_PlaneExtractionActionFeedback" :depends-on ("_package"))
    (:file "TableObjectClusterActionGoal" :depends-on ("_package_TableObjectClusterActionGoal"))
    (:file "_package_TableObjectClusterActionGoal" :depends-on ("_package"))
    (:file "PlaneExtractionFeedback" :depends-on ("_package_PlaneExtractionFeedback"))
    (:file "_package_PlaneExtractionFeedback" :depends-on ("_package"))
    (:file "PlaneExtractionAction" :depends-on ("_package_PlaneExtractionAction"))
    (:file "_package_PlaneExtractionAction" :depends-on ("_package"))
    (:file "TableObjectClusterGoal" :depends-on ("_package_TableObjectClusterGoal"))
    (:file "_package_TableObjectClusterGoal" :depends-on ("_package"))
    (:file "PlaneExtractionGoal" :depends-on ("_package_PlaneExtractionGoal"))
    (:file "_package_PlaneExtractionGoal" :depends-on ("_package"))
    (:file "TriggerActionGoal" :depends-on ("_package_TriggerActionGoal"))
    (:file "_package_TriggerActionGoal" :depends-on ("_package"))
    (:file "PlaneExtractionResult" :depends-on ("_package_PlaneExtractionResult"))
    (:file "_package_PlaneExtractionResult" :depends-on ("_package"))
    (:file "TriggerGoal" :depends-on ("_package_TriggerGoal"))
    (:file "_package_TriggerGoal" :depends-on ("_package"))
    (:file "PlaneExtractionActionResult" :depends-on ("_package_PlaneExtractionActionResult"))
    (:file "_package_PlaneExtractionActionResult" :depends-on ("_package"))
    (:file "TableObjectClusterActionResult" :depends-on ("_package_TableObjectClusterActionResult"))
    (:file "_package_TableObjectClusterActionResult" :depends-on ("_package"))
    (:file "TriggerResult" :depends-on ("_package_TriggerResult"))
    (:file "_package_TriggerResult" :depends-on ("_package"))
    (:file "TriggerActionResult" :depends-on ("_package_TriggerActionResult"))
    (:file "_package_TriggerActionResult" :depends-on ("_package"))
    (:file "Point2D" :depends-on ("_package_Point2D"))
    (:file "_package_Point2D" :depends-on ("_package"))
    (:file "CurvedPolygonArray" :depends-on ("_package_CurvedPolygonArray"))
    (:file "_package_CurvedPolygonArray" :depends-on ("_package"))
    (:file "Feature" :depends-on ("_package_Feature"))
    (:file "_package_Feature" :depends-on ("_package"))
    (:file "Shape" :depends-on ("_package_Shape"))
    (:file "_package_Shape" :depends-on ("_package"))
    (:file "PolylinePoint" :depends-on ("_package_PolylinePoint"))
    (:file "_package_PolylinePoint" :depends-on ("_package"))
    (:file "Plane" :depends-on ("_package_Plane"))
    (:file "_package_Plane" :depends-on ("_package"))
    (:file "ShapeArray" :depends-on ("_package_ShapeArray"))
    (:file "_package_ShapeArray" :depends-on ("_package"))
    (:file "PlaneScene" :depends-on ("_package_PlaneScene"))
    (:file "_package_PlaneScene" :depends-on ("_package"))
    (:file "FilterObject" :depends-on ("_package_FilterObject"))
    (:file "_package_FilterObject" :depends-on ("_package"))
    (:file "SimilarityScore" :depends-on ("_package_SimilarityScore"))
    (:file "_package_SimilarityScore" :depends-on ("_package"))
    (:file "Polygon" :depends-on ("_package_Polygon"))
    (:file "_package_Polygon" :depends-on ("_package"))
    (:file "CurvedPolygon" :depends-on ("_package_CurvedPolygon"))
    (:file "_package_CurvedPolygon" :depends-on ("_package"))
  ))