/**
 *  @file   PandoraPFANew/Framework/include/Managers/ParticleFlowObjectManager.h
 * 
 *  @brief  Header file for the particle flow object manager class.
 * 
 *  $Log: $
 */
#ifndef PANDORA_PARTICLE_FLOW_OBJECT_MANAGER_H
#define PANDORA_PARTICLE_FLOW_OBJECT_MANAGER_H 1

#include "Api/PandoraContentApi.h"

#include "Managers/AlgorithmObjectManager.h"

#include "Pandora/PandoraInternal.h"

namespace pandora
{

/**
 *  @brief  ParticleFlowObjectManager class
 */
class ParticleFlowObjectManager : public AlgorithmObjectManager<ParticleFlowObject>
{
    public:
    /**
     *  @brief  Default constructor
     */
     ParticleFlowObjectManager();

    /**
     *  @brief  Destructor
     */
     ~ParticleFlowObjectManager();

private:
    /**
     *  @brief  Create a particle flow object
     * 
     *  @param  particleFlowObjectParameters the particle flow object parameters
     *  @param  pPfo to receive the address of the particle flow object created
     */
    StatusCode CreateParticleFlowObject(const PandoraContentApi::ParticleFlowObject::Parameters &particleFlowObjectParameters,
        ParticleFlowObject *&pPfo);

    /**
     *  @brief  Add a cluster to a particle flow object
     *
     *  @param  pPfo address of the particle flow object to modify
     *  @param  pCluster address of the cluster to add
     */
    StatusCode AddClusterToPfo(ParticleFlowObject *pPfo, Cluster *pCluster) const;

    /**
     *  @brief  Add a track to a particle flow object
     *
     *  @param  pPfo address of the particle flow object to modify
     *  @param  pTrack address of the track to add
     */
    StatusCode AddTrackToPfo(ParticleFlowObject *pPfo, Track *pTrack) const;

    /**
     *  @brief  Add a parent-daughter particle flow object relationship
     *
     *  @param  pParentPfo address of parent particle flow object
     *  @param  pDaughterPfo address of daughter particle flow object
     */
    StatusCode SetParentDaughterAssociation(ParticleFlowObject *pParentPfo, ParticleFlowObject *pDaughterPfo) const;

    /**
     *  @brief  Remove a cluster from a particle flow object. Note this function will not remove the final object (track or cluster)
     *          from a particle flow object, and will instead return status code "not allowed" as a prompt to delete the cluster
     *
     *  @param  algorithm the algorithm calling this function
     *  @param  pPfo address of the particle flow object to modify
     *  @param  pCluster address of the cluster to remove
     */
    StatusCode RemoveClusterFromPfo(ParticleFlowObject *pPfo, Cluster *pCluster);

    /**
     *  @brief  Remove a track from a particle flow object. Note this function will not remove the final object (track or cluster)
     *          from a particle flow object, and will instead return status code "not allowed" as a prompt to delete the cluster
     *
     *  @param  pPfo address of the particle flow object to modify
     *  @param  pTrack address of the track to remove
     */
    StatusCode RemoveTrackFromPfo(ParticleFlowObject *pPfo, Track *pTrack);

    /**
     *  @brief  Remove a parent-daughter particle flow object relationship
     *
     *  @param  pParentPfo address of parent particle flow object
     *  @param  pDaughterPfo address of daughter particle flow object
     */
    StatusCode RemoveParentDaughterAssociation(ParticleFlowObject *pParentPfo, ParticleFlowObject *pDaughterPfo) const;

    friend class PandoraApiImpl;
    friend class PandoraContentApiImpl;
    friend class PandoraImpl;
};

} // namespace pandora

#endif // #ifndef PANDORA_PARTICLE_FLOW_OBJECT_MANAGER_H
