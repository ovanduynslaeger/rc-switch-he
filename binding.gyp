{
  'targets': [
    {
      'target_name': 'rcswitchhe',
      'sources': [ 'src/rcswitchhe.cpp','src/RCSwitchHENode.cpp','externals/RCSwitchHE.cpp' ],
      'include_dirs': [ '/usr/local/include', "<!(node -e \"require('nan')\")" ],
      'ldflags': [ '-lwiringPi' ]
    }
  ]
}
