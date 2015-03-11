{
  'targets': [
    {
      'target_name': 'rcswitchhe',
      'sources': [ 'src/RCSwitchHENode.cpp', 'externals/RCSwitchHE.cpp' ],
      'include_dirs': [ '/usr/local/include' ],
      'ldflags': [ '-lwiringPi' ]
    }
  ]
}
