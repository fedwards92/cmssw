#include "TrackingTools/DetLayers/interface/GeomDetCompatibilityChecker.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h" 


std::pair<bool, TrajectoryStateOnSurface>  
GeomDetCompatibilityChecker::isCompatible(const GeomDet* theDet,
					  const TrajectoryStateOnSurface& tsos,
					  const Propagator& prop, 
					  const MeasurementEstimator& est) {
  TrajectoryStateOnSurface && propSt = prop.propagate( tsos, theDet->specificSurface());
  if unlikely ( !propSt.isValid()) return std::make_pair( false, std::move(propSt));
  auto es = est.estimate( propSt, theDet->specificSurface());
  return std::make_pair( es, std::move(propSt));

}
 
